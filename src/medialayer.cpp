/** medialayer.cpp
 *
 * 
 */

#include "medialayer.h"

bool MediaLayer::MediaLayer_Initialize(MediaLayer* layer, int window_width, int window_height){
    return layer->initialize(window_width, window_height);
}

void MediaLayer::MediaLayer_Shutdown(MediaLayer* layer){
    layer->shutdown();
}

MEDIALAYER_KEY_CODE MediaLayer::MediaLayer_GetInput(MediaLayer* layer){
    return layer->get_input();
}