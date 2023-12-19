// kanontoren.h
#ifndef KANONTOREN_H
#define KANONTOREN_H

#include "toren.h"
namespace justice
{
class Game;
class kanontoren : public toren
{
public://polymorfisme
    kanontoren();
    // Destructor
    ~kanontoren();
protected://polymorfisme
  
    // Constructor met standaardwaarden voor attributen
    
    void schiet(int xgeschoten, int ygeschoten, int xveld, int yveld, int scoretype) override;
    friend class Game;
};
}
#endif // KANONTOREN_H
