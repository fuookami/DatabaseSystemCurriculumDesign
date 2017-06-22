DROP TABLE DSCD.Groups;
CREATE TABLE DSCD.Groups (
  id   INTEGER PRIMARY KEY,
  name NVARCHAR2(40) NOT NULL
);

DROP TABLE DSCD.Addresses;
CREATE TABLE DSCD.Addresses (
  id        INTEGER PRIMARY KEY,
  name      NVARCHAR2(40) NOT NULL,
  mobile    VARCHAR2(20)  DEFAULT NULL,
  mobile2   VARCHAR2(20)  DEFAULT NULL,
  telephone VARCHAR2(20)  DEFAULT NULL,
  unit      NVARCHAR2(40) DEFAULT NULL,
  identity  NVARCHAR2(40) DEFAULT NULL,
  remark    NVARCHAR2(40) DEFAULT NULL,
  email     NCLOB         DEFAULT NULL,
  group_id  INTEGER       DEFAULT NULL
);

DROP TABLE DSCD.Records;
CREATE TABLE DSCD.Records (
  id           INTEGER PRIMARY KEY,
  phone_number VARCHAR2(20) NOT NULL,
  bg_time      TIMESTAMP    NOT NULL,
  ed_time      TIMESTAMP    NOT NULL,
  address_id   INTEGER,
  CHECK (ed_time > bg_time)
);

DROP VIEW DSCD.PHONE_NUMBER_2_ADDRESS;
CREATE VIEW DSCD.PHONE_NUMBER_2_ADDRESS AS (
  SELECT id, mobile as phone_number FROM DSCD.Addresses WHERE mobile IS NOT NULL
  UNION
  SELECT id, mobile2 as phone_number FROM DSCD.Addresses WHERE mobile2 IS NOT NULL
  UNION
  SELECT id, telephone as phone_number FROM DSCD.Addresses WHERE telephone IS NOT NULL
);

DROP SEQUENCE DSCD.seq_DSCD_Group_id;
CREATE SEQUENCE DSCD.seq_DSCD_Group_id
  INCREMENT BY 1
  START WITH 1
  NOMAXVALUE
  NOCYCLE
  NOCACHE ;

DROP SEQUENCE DSCD.seq_DSCD_Address_id;
CREATE SEQUENCE DSCD.seq_DSCD_Address_id
  INCREMENT BY 1
  START WITH 1
  NOMAXVALUE
  NOCYCLE
  NOCACHE ;

DROP SEQUENCE DSCD.seq_DSCD_Record_id;
CREATE SEQUENCE DSCD.seq_DSCD_Record_id
  INCREMENT BY 1
  START WITH 1
  NOMAXVALUE
  NOCYCLE
  NOCACHE ;

CREATE OR REPLACE TRIGGER DSCD.INSERT_DSCD_Address
BEFORE INSERT ON DSCD.Addresses
  FOR EACH ROW
  DECLARE
    group_num INTEGER;
  BEGIN
    SELECT COUNT(id) INTO group_num FROM DSCD.Groups WHERE id = :NEW.group_id;
    IF (:NEW.group_id IS NOT NULL AND group_num = 0) THEN
      :NEW.group_id := NULL;
    END IF;

    UPDATE DSCD.Records SET address_id = :NEW.id WHERE phone_number = :NEW.MOBILE OR
      phone_number = :NEW.MOBILE2 OR phone_number = :NEW.TELEPHONE;
  END;

CREATE OR REPLACE TRIGGER DSCD.UPDATE_DSCD_Address
BEFORE UPDATE ON DSCD.Addresses
  FOR EACH ROW
  DECLARE
    group_num INTEGER;
  BEGIN
    SELECT COUNT(id) INTO group_num FROM DSCD.Groups WHERE id = :NEW.group_id;
    IF (:NEW.group_id IS NOT NULL AND group_num = 0) THEN
      :NEW.group_id := NULL;
    END IF;

    UPDATE DSCD.Records SET address_id = :NEW.id WHERE phone_number = :NEW.MOBILE OR
      phone_number = :NEW.MOBILE2 OR phone_number = :NEW.TELEPHONE;
  END;

CREATE OR REPLACE TRIGGER DSCD.DELETE_DSCD_Address
BEFORE DELETE ON DSCD.Addresses
  FOR EACH ROW
  BEGIN
    UPDATE DSCD.Records SET address_id = NULL WHERE address_id = :OLD.id;
  END;

CREATE OR REPLACE TRIGGER DSCD.INSERT_DSCD_Record
BEFORE INSERT ON DSCD.Records
  FOR EACH ROW
  DECLARE
    address_num INTEGER;
    address_id INTEGER;
  BEGIN
    SELECT COUNT(*) into address_num FROM DSCD.PHONE_NUMBER_2_ADDRESS
    WHERE phone_number = :NEW.phone_number;
    IF (address_num > 0) THEN
      SELECT id into address_id FROM DSCD.PHONE_NUMBER_2_ADDRESS
      WHERE phone_number = :NEW.phone_number;
      :NEW.address_id := address_id;
    END IF;
  END;

COMMIT;