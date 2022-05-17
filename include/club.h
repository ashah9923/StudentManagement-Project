#ifndef CLUB_H
#define CLUB_H
#include <string>

class club
{
    private:
    std::string activity; 
    
    public:
    club(std::string activity)
    {
        this->activity = activity;
    };
    void setActivity(std::string);
    std::string getActivity();
};

#endif