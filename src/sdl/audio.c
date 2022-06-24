#include "audio.h"
#include "../options.h"
#include <SDL.h>
#include <SDL_audio.h>
#include <stdio.h>
#include "../cmixer/cmixer.h"
#include <string.h>

int music_volume = 4;
static cm_Source* music = NULL;

static void audio_callback(void *udata, Uint8 *stream, int size) {
    cm_process((void*) stream, size / 2);
}

void PHL_AudioInit()
{
    SDL_AudioSpec des, obt;
    SDL_InitSubSystem(SDL_INIT_AUDIO);
    memset(&obt, 0, sizeof(obt));
    memset(&des, 0, sizeof(des));
    des.freq      = 44100;
    des.format    = AUDIO_S16;
    des.channels  = 2;
    des.samples   = 1024;
    des.callback  = audio_callback;

    if (SDL_OpenAudio(&des, &obt) < 0) {
        fprintf(stderr, "Error: failed to open audio device '%s'\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    cm_init(44100);
    SDL_PauseAudio(0);
    cm_set_master_gain(0.25f * music_volume);
}

void PHL_AudioClose()
{
    SDL_CloseAudio();
}

//Same as PHL_LoadSound, but expects a file name without extension
PHL_Music PHL_LoadMusic(char* fname, int loop)
{
    PHL_Music ret;
    ret.loop = loop;
    char buff[4096];
    strcpy(buff, "data/");
    strcat(buff, fname);
    strcat(buff, ".ogg");

    ret.snd = cm_new_source_from_file(buff);
    music = ret.snd;
    return ret;
}

PHL_Sound PHL_LoadSound(char* fname)
{
    char buff[4096];
    strcpy(buff, "data/");
    strcat(buff, fname);
    return cm_new_source_from_file(buff);
}

void PHL_MusicVolume(float vol)
{
    cm_set_master_gain(vol);
}

void PHL_PlayMusic(PHL_Music snd)
{
    if(snd.snd) {
        cm_set_loop(snd.snd, snd.loop ? 0 : 1);
        cm_play(snd.snd);
    }
}

void PHL_PlaySound(PHL_Sound snd, int channel)
{
    cm_play(snd);
}

void PHL_StopMusic()
{
    cm_stop(music);
}

void PHL_StopSound(PHL_Sound snd, int channel)
{
    cm_stop(snd);
}

void PHL_FreeMusic(PHL_Music snd)
{
    if(snd.snd)
        cm_destroy_source(snd.snd);
    music = snd.snd = NULL;
}

void PHL_FreeSound(PHL_Sound snd)
{
    cm_destroy_source(snd);
}
