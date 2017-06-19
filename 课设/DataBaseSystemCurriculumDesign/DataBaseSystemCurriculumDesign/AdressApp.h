#pragma once

class AddressApp
{
public:
	static AddressApp &getReference(void);

	AddressApp();
	~AddressApp();

	void run();

private:
	void loadSettingDatas();

private:
	// loading window
	// main window
};