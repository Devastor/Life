//
//  Timer.hpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

class Timer
{
    // Methods
public:
    Timer();
    ~Timer();
    
    // This returns the number of milliseconds since this object was created.
    float timeSinceCreation();
    
    // This method returns the number of milliseconds that have passed since it was last called.
    float timeSinceLastFrame();
    
    // Data
private:
    // This stores the time of that last call to timeSinceLastFrame().
    float m_timeOfLastCall;
};

#endif /* Timer_hpp */
