/** medialayer.h
 *
 * Interface for receiving input from devices, 
 * and sending output to screen. Probably completely
 * unnecessary and perhaps a waste of time.
 * 
 * 
 * 
 */
#ifndef MEDIALAYER_H
#define MEDIALAYER_H

enum MEDIALAYER_KEY_CODE{
    MEDIALAYER_KEY_NULL=0,
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

    static bool MediaLayer_Initialize(MediaLayer* layer, int window_width, int window_height);
    static void MediaLayer_Shutdown(MediaLayer* layer);
    static MEDIALAYER_KEY_CODE MediaLayer_GetInput(MediaLayer* layer);

    MediaLayer(){};
    virtual ~MediaLayer(){};

    virtual bool initialize() =0;
    virtual bool initialize(int window_width, int window_height) =0;
    virtual bool initialize(int window_width, int window_height, int window_x, int window_y) =0;
    virtual void shutdown() =0;

    virtual bool create_window() =0;
    virtual MEDIALAYER_KEY_CODE get_input() =0;
    virtual double delta_time() =0;

    virtual void draw() =0;

protected:

    int _window_width, _window_height;          // Window size
    int _win_coordinate_x, _win_coordinate_y;   // Coordinate where the window will be created

    int _ticks_count{0};                // For calculating delta time
    const int _ms_per_frame{16};        // For delta time: 60fps = apprx. 1 frame per 16ms
    const double _delta_max{0.05};      // Cap for delta time, in seconds

private:

};
#endif