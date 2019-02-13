#pragma once

#ifdef AUDIO_ENABLE
//    #define STARTUP_SONG SONG(NO_SOUND)
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
#define TAPPING_TERM 200

#define UNICODE_SONG_WIN UNICODE_WINDOWS
#define UNICODE_SONG_LNX UNICODE_LINUX
