#pragma once
class Glasses
{
private:
	int _price;
	bool _IsBeatiful;
	bool _IsDarkened;
	int _VisionCorrection;
	bool _Wearing;
public:
	Glasses();
	Glasses(int price, bool IsBeatiful,
		bool IsDarkened, int VisionCorrection,
		bool Wearing);
	int GetPrice() const;
	bool GetIsBeatiful() const;
	bool GetIsDarkened() const;
	int GetVisionCorrection() const;
	bool GetWearing() const;

	void SetPrice(int price);
	void SetIsBeatiful(bool IsBeatiful);
	void SetIsDarkened(bool IsDarkened);
	void SetVisionCorrection(int VisionCorrection);
	void SetWearing(bool _Wearing);
	void Print();
};

