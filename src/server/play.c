/*
** play.c for cmp in /home/guillaume/Documents/Projets/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Wed Apr 20 16:25:29 2016 guillaume
** Last update Tue May  3 12:24:22 2016 guillaume
*/

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include "fmod.h"
#include "wincompat.h"
#include "cmp-server.h"

void	checkerror(FMOD_RESULT result)
{
  if (result != FMOD_OK)
    {
      printf("FMOD error!\n");
      exit(-1);
    }
}

void	init_system()
{
  FMOD_RESULT	result;

  result = FMOD_System_Create(&music.system);
  checkerror(result);

  result = FMOD_System_Init(music.system, 32, FMOD_INIT_NORMAL, NULL);
  checkerror(result);

  if ((music.rep = opendir(path_music)) == NULL)
    {
      printf("Error : %s\n", strerror(errno));
      exit(-1);
    }
  chdir(path_music);
  load_playlist();
}

int	play()
{
  FMOD_RESULT	result;
  int	key;
  int	lenms;
  int	ms;
  static int	lecture = -1;

  FMOD_Channel_IsPlaying(music.channel, &music.isplaying);

  if (!music.isplaying)
    {
      result = -1;
      while (result != FMOD_OK)
	{
	  lecture++;
	  if (lecture >= music.nbsong)
	    lecture = 0;
	  FMOD_Sound_Release(music.music);
	  result = FMOD_System_CreateSound(music.system, music.playlist[lecture], FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
	}
      FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
      aff(lecture);
    }
  if (cmd != '\0')
    {
      if (cmd == 'n')
	lecture = next_music(lecture);
      else if (cmd == 'p')
	lecture = prev_music(lecture);
      cmd = '\0';
    }
  if (kbhit())
    {
      cmd = getch();

      if (cmd == 'q')
	quit();
      else if (cmd == 'n')
	lecture = next_music(lecture);
      else if (cmd == 'p')
	lecture = prev_music(lecture);
      else if (cmd == 'r')
	{
	  free(music.playlist);
	  system("clear");
	  printf("! Reloading !\n");
	  load_playlist();
	  sleep(1);
	  aff(lecture);
	}
      else if (cmd == 's')
	pausemusic(lecture);
      cmd = 0;
    }
  FMOD_Channel_GetPosition(music.channel, &ms, FMOD_TIMEUNIT_MS);
  FMOD_Sound_GetLength(music.music, &lenms, FMOD_TIMEUNIT_MS);
  int	test;
  int	tmp = 100;
  test = (100 * ms) / lenms;
  printf("%02d:%02d:%02d |", ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100);
  while (tmp != 0)
    {
      while (test > 0)
	{
	  printf("=");
	  test = test - 2;
	  tmp = tmp - 2;
	}
      printf(" ");
      tmp = tmp - 2;
    }
  printf("| %02d:%02d:%02d\r", lenms / 1000 / 60, lenms / 1000 % 60, lenms / 10 % 100);
  fflush(stdout);
  return (0);
}

void	aff(int lecture)
{
  system("clear");
  copyright_display();
  display_conf();
  FMOD_Channel_GetPaused(music.channel, &music.pause);
  printf("%s ", (!music.pause) ? "►" : "‖");
  printf("%d/%d - %s\n", lecture + 1, music.nbsong, music.playlist[lecture]);
}

void	pausemusic(int lecture)
{
  FMOD_Channel_GetPaused(music.channel, &music.pause);
  if (music.pause)
    FMOD_Channel_SetPaused(music.channel, 0);
  else if (!music.pause)
    FMOD_Channel_SetPaused(music.channel, 1);
  aff(lecture);
  }

void	quit()
{
  closedir(music.rep);
  FMOD_Sound_Release(music.music);
  FMOD_System_Close(music.system);
  FMOD_System_Release(music.system);
  exit(0);
}

int	next_music(int lecture)
{
  FMOD_RESULT	result;

  FMOD_Sound_Release(music.music);
  result = -1;
  while (result != FMOD_OK)
    {
      lecture++;
      if (lecture >= music.nbsong)
	lecture = 0;
      FMOD_Sound_Release(music.music);
      result = FMOD_System_CreateSound(music.system, music.playlist[lecture], FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
    }
  FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
  aff(lecture);
  return (lecture);
}

int	prev_music(int lecture)
{
  FMOD_RESULT	result;

  FMOD_Sound_Release(music.music);
  result = -1;
  while (result != FMOD_OK)
    {
      lecture--;
      if (lecture < 0)
	lecture = music.nbsong - 1;
      FMOD_Sound_Release(music.music);
      result = FMOD_System_CreateSound(music.system, music.playlist[lecture], FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
    }
  FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
  aff(lecture);
  return (lecture);
}
