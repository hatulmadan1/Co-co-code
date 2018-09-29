#ifndef BIG_INTEGER
#define BIG_INTEGER

#include <vector>
#include <functional>

class big_integer {

public:
	bool sign;

	std::vector<uint32_t> m_data;

	big_integer();
	big_integer(big_integer const &x);
	big_integer(int a);
	explicit big_integer(const std::string &str);
	~big_integer() = default;

	big_integer &operator=(big_integer const &other);

	big_integer &operator+=(big_integer const &b);
	big_integer &operator-=(big_integer const &b);
	big_integer &operator*=(big_integer const &b);
	big_integer &operator/=(big_integer const &b);

	big_integer &operator%=(big_integer const &b);

	big_integer &operator&=(big_integer const &b);
	big_integer &operator|=(big_integer const &b);
	big_integer &operator^=(big_integer const &rhs);

	big_integer &operator<<=(int x);
	big_integer &operator>>=(int x);

	big_integer operator+() const;
	big_integer operator-() const;
	big_integer operator~() const;

	big_integer &operator++();
	big_integer &operator--();
	big_integer operator++(int);
	big_integer operator--(int);

	friend bool operator==(big_integer const &a, big_integer const &b);
	friend bool operator!=(big_integer const &a, big_integer const &b);
	friend bool operator<(big_integer const &a, big_integer const &b);
	friend bool operator>(big_integer const &a, big_integer const &b);
	friend bool operator<=(big_integer const &a, big_integer const &b);
	friend bool operator>=(big_integer const &a, big_integer const &b);

	friend std::string to_string(big_integer const &a);

	void del_zeros();

	bool is_zero() const;
	size_t length() const;


	void move(big_integer const& from);
	std::pair<big_integer, uint32_t>    div_mod(uint32_t dividend) const;
	std::pair<big_integer, big_integer> div_mod(big_integer const &b) const;

	friend big_integer apply_compl(big_integer const& x, big_integer const& y, std::function<uint32_t(uint32_t, uint32_t)> F);
	friend std::vector<uint32_t> get_com(big_integer const& x);
	friend big_integer get_dec(std::vector<uint32_t> const& x);

	friend std::vector<uint32_t> apply_vec(std::vector<uint32_t> const &x, std::vector<uint32_t> const &y, std::function<uint32_t(uint32_t, uint32_t)> F);
	friend big_integer apply_compl(big_integer const &x, big_integer const &y, std::function<uint32_t(uint32_t, uint32_t)> F);
	friend big_integer get_dec(std::vector<uint32_t> const &x);
	friend std::vector<uint32_t> get_com(big_integer const &x);
};
big_integer operator+(big_integer a, big_integer const &b);
big_integer operator-(big_integer a, big_integer const &b);
big_integer operator*(big_integer a, big_integer const &b);
big_integer operator/(big_integer a, big_integer const &b);

big_integer operator%(big_integer a, big_integer const &b);

big_integer operator&(big_integer a, big_integer const &b);
big_integer operator|(big_integer a, big_integer const &b);
big_integer operator^(big_integer a, big_integer const &b);

bool operator==(big_integer const &a, big_integer const &b);
bool operator!=(big_integer const &a, big_integer const &b);
bool operator<(big_integer const &a, big_integer const &b);
bool operator>(big_integer const &a, big_integer const &b);
bool operator<=(big_integer const &a, big_integer const &b);
bool operator>=(big_integer const &a, big_integer const &b);

big_integer operator<<(big_integer a, int x);
big_integer operator >> (big_integer a, int x);

big_integer abs(big_integer const &x);

std::string to_string(big_integer const &a);
std::ostream& operator<<(std::ostream& s, big_integer const& a);


#endif // !BIG_INTEGER
