#ifndef GIF_H
#define GIF_H
#include <string>
#include "../inc/app_cfg.h"
class Gif
{
public:
    Gif(const std::string &_gifName = "") :
		gifName(_gifName){}
    
	~Gif() {}

    /* setter */
	void setGifName(const std::string &_gifName) { gifName = _gifName; }
    void setGifID(const us16 _id) { id = _id; }

    /* getter */
    const std::string& getGifName() { return gifName; }
    const us16 getGifID() { return id; }

private:
    us16 id;
	std::string gifName;
};
#endif // GIF_H
