#ifndef GIF_H
#define GIF_H
#include <string>
class Gif
{
public:
	Gif(const std::string &_username = "",
		const std::string &_gifName = "") :
		username(_username),
		gifName(_gifName){}
	~Gif() {}

	/* getter */
	void setUsername(const std::string &_username) { username = _username; }
	void setGifName(const std::string &_gifName) { gifName = _gifName; }

	/* setter */
	const std::string getUsername() { return username; }
	const std::string getGifName() { return gifName; }

private:
	std::string username;
	std::string gifName;
};
#endif // GIF_H
