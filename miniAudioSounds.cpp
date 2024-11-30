#define MINIAUDIO_IMPLEMENTATION
#include "miniAudioSounds.h"
#include <stdio.h>
#include <unistd.h>
#include <chrono>
using namespace std;
void mini::playMenuTheme(bool * stop, char * filename)
{
    ma_result result;
    ma_engine engine;
    ma_sound sound;

    ma_sound_set_fade_in_milliseconds(&sound, 0, 1, 1000);

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return;
    }
    //ma_engine_play_sound(&engine, filename, NULL);
    result = ma_sound_init_from_file(&engine, filename, 0, NULL, NULL, &sound);
    ma_sound_start(&sound);
    ma_sound_set_looping(&sound, true);
    //ma_sound_set_fade_in_milliseconds(&sound, -1, 0, 1000);

    //double microsecond = 1000000;
    //sleep_until(system_clock::now() + seconds(300));
    while (true) {
        if (*stop == true) {
            ma_sound_set_fade_in_milliseconds(&sound, -1, 0, 1000);
            usleep(1 * 1000000);
            ma_engine_uninit(&engine);
            return;
        }
    }
    

    return;
}