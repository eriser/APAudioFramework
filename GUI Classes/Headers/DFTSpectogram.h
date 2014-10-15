//
//  AnalysisWindowComponent.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 9/30/14.
//
//

#ifndef FPTAnalyzer_AnalysisWindowComponent_h
#define FPTAnalyzer_AnalysisWindowComponent_h

#include "DFTAnalyzer.h"
#include "WaveletTransform.h"
#include "TransientProcessor.h"
#include "APAudioFileManager2.h"
#include "FrequencyAnalyzer.h"
#include <iostream>

class DFTSpectogram: public Component
{
public:
    DFTSpectogram(APAudioFileManager* fileManager);
    DFTSpectogram();
    
    void resized() override final;
    void paint(Graphics& g) override final;
    void getDrawData();
    void mouseUp (const MouseEvent& event) override final;
    void mouseDown(const MouseEvent& event) override final;
//    void mouseMove(const MouseEvent& event)override;
    
private:
    
    APAudioFileManager* _fileManager;
    
    void draw(juce::Graphics& g);
    void drawDFTSpectogram(Graphics& g);
    void drawScale(Graphics& g);

    bool _dataWasRead = 0;
    bool _drawPathWasSet = 0;
    Path _drawPath;
};

#endif