/** medialayer.cpp
 *
 * I am worried this is a bad way to do what I want to do
 * 
 */

#include "medialayer.h"

/** function: MediaLayer_Initialize()
 *
 * 
 */
bool MediaLayer::MediaLayer_Initialize(MediaLayer* layer, int window_width, int window_height){
    return layer->initialize(window_width, window_height);
}

/** function: MediaLayer_Shutdown()
 *
 * 
 */
void MediaLayer::MediaLayer_Shutdown(MediaLayer* layer){
    layer->shutdown();
}

/** function: MediaLayer_GetInput()
 *
 * 
 */
MEDIALAYER_KEY_CODE MediaLayer::MediaLayer_GetInput(MediaLayer* layer){
    return layer->get_input();
}

/** function: MediaLayer_GenerateOutput()
 *
 * 
 */
void MediaLayer::MediaLayer_GenerateOutput(MediaLayer* layer){
    layer->generate_output();
}