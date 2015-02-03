//
//  APAudioParameter.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioParameter__
#define __APAudioEngine__APAudioParameter__

#include <string>

template<typename T>
class Parameter
{
public:
    Parameter(){};
    Parameter(T min,
              T max,
              T start,
              std::string identification)
    {
        _minValue = min;
        _maxValue = max;
        _currentValue = start;
        
        _ID = identification;
    }
    
    void setMinValue(T value){_minValue = value;};
    void setMaxValue(T value){_maxValue = value;};
    void setID(std::string id){_ID = id;};
    
    void setValue(T value)
    {
        if(value > _maxValue) return;
        else if(value < _minValue) return;
        else _currentValue = value;
    };
    
    Parameter& operator= (const T& value)
    {
        setValue(value); return *this;
    };
    
    Parameter& operator= (const std::string& id)
    {
        setID(id); return *this;
    };
    
    Parameter& operator+= (const T& value)
    {
        setValue(value + _currentValue); return *this;
    };
    
    Parameter& operator-= (const T& value)
    {
        setValue(_currentValue - value); return *this;
    };
    
    Parameter& operator++ (int)
    {
        setValue(_currentValue++); return *this;
    };
    
    Parameter& operator++ ()
    {
        setValue(++_currentValue); return *this;
    };
    
    Parameter& operator-- (int)
    {
        setValue(_currentValue--); return *this;
    };
    
    Parameter& operator-- ()
    {
        setValue(--_currentValue); return *this;
    };
    
    inline T getMinValue(){return _minValue;};
    inline T getMaxValue(){return _maxValue;};
    inline T getValue(){return _currentValue;};
    inline std::string  getID(){return _ID;};
    
private:
    
    T _minValue;
    T _maxValue;
    T _currentValue;
    
    std::string _ID;
};

#endif /* defined(__APAudioEngine__APAudioParameter__) */