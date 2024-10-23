#define MINIAUDIO_IMPLEMENTATION
#include "miniAudioSounds.h"
#include <stdio.h>
#include <unistd.h>
#include <chrono>
using namespace std;
void mini::playMenuTheme(bool * stop)
{
    ma_result result;
    ma_engine engine;


    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return;
    }
    ma_engine_play_sound(&engine, "Versus.mp3", NULL);

    //double microsecond = 1000000;
    //sleep_until(system_clock::now() + seconds(300));
    while (true) {
        if (*stop == true) {
            ma_engine_uninit(&engine);
            return;
        }
    }
    

    return;
}