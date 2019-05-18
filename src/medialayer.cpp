/** medialayer.cpp
 *
 * I am worried this is a bad way to do what I want to do
 * 
 */

#include <vector>
#include "medialayer.h"

/** function: clear_shapes()
 * 
 */
void MediaLayer::clear_shapes(){
    if(!_shapes.empty()){
        _shapes.clear();
    }
}

/** function: add_shape()
 * 
 */
void MediaLayer::add_shape(std::vector<Vector2d> shape){
    _shapes.push_back(shape);
}

// ----------------------------------------------------------------------

/** function: MediaLayer_Initialize()
 * 
 */
bool MediaLayer::MediaLayer_Initialize(MediaLayer* layer, int window_width, int window_height){
    return layer->initialize(window_width, window_height);
}

/** function: MediaLayer_Shutdown()
 *
 */
void MediaLayer::MediaLayer_Shutdown(MediaLayer* layer){
    layer->shutdown();
}

/** function: MediaLayer_GetInput()
 * 
 */
std::vector<Medialayer_Key_Code> MediaLayer::MediaLayer_GetInput(MediaLayer* layer){
    return layer->get_input();
}

/** function: MediaLayer_GenerateOutput()
 * 
 */
void MediaLayer::MediaLayer_GenerateOutput(MediaLayer* layer){
    layer->generate_output();
}

/** function MediaLayer_GetDeltaTime()
 * 
 */
double MediaLayer::MediaLayer_GetDeltaTime(MediaLayer* layer){
    return layer->get_delta_time();
}