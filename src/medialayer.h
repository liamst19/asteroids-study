/** medialayer.h
 *
 * Interface for receiving input from devices, 
 * and sending output to screen. Probably completely
 * unnecessary and perhaps a waste of time.
 * 
 */
#ifndef MEDIALAYER_H
#define MEDIALAYER_H

// Keyboard inputs and window events
enum MEDIALAYER_KEY_CODE{
    MEDIALAYER_KEY_NULL=0, // Default
    MEDIALAYER_KEY_QUIT,
    MEDIALAYER_KEY_ESC,
    MEDIALAYER_KEY_SPC,
    MEDIALAYER_KEY_W,
    MEDIALAYER_KEY_A,
    MEDIALAYER_KEY_S,
    MEDIALAYER_KEY_D,
    MEDIALAYER_KEY_SEMICOLON
};

class MediaLayer{

public:

    MediaLayer(){};
    virtual ~MediaLayer(){};

    // Wrapper function for initializing media layer object
    static bool MediaLayer_Initialize(MediaLayer* layer, int window_width, int window_height);

    // Wrapper function for shutting down media layer object
    static void MediaLayer_Shutdown(MediaLayer* layer);

    // Wrapper function for retrieving keyboard input
    static MEDIALAYER_KEY_CODE MediaLayer_GetInput(MediaLayer* layer);

    // Wrapper function for rendering screen
    static void MediaLayer_GenerateOutput(MediaLayer* layer);

    // Initializes media layer
    virtual bool initialize() =0;

    // Initializes media layer with window dimension, positions window at the center of screen
    virtual bool initialize(int window_width, int window_height) =0;

    // Initializes media layer with window dimention and position
    virtual bool initialize(int window_width, int window_height, int window_x, int window_y) =0;

    // Shuts down media layer
    virtual void shutdown() =0;

    // Renders output to screen
    virtual void generate_output() =0;

    // Creates and opens window
    virtual bool create_window() =0;

    // Adds object to be rendered to screen
    virtual void draw() =0;

    // Retrieves input from devices
    virtual MEDIALAYER_KEY_CODE get_input() =0;

    // Calculates delta time
    virtual double delta_time() =0;

protected:

    int _window_width, _window_height;          // Window size
    int _win_coordinate_x, _win_coordinate_y;   // Coordinate where the window will be created

    int _ticks_count{0};                // For calculating delta time
    const int _ms_per_frame{16};        // For delta time: 60fps = apprx. 1 frame per 16ms
    const double _delta_max{0.05};      // Cap for delta time, in seconds

private:

};
#endif