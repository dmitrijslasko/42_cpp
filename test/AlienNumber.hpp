class AlienNumber {
	
	private:
		const static int _ALIEN_FACTOR = 2;
		int _value;

	public:

		AlienNumber(int value) : _value(value) {}
		
		AlienNumber operator+(const AlienNumber& other);
		AlienNumber operator-(const AlienNumber& other);

		int getValue() const {
			return _value;
		}
};