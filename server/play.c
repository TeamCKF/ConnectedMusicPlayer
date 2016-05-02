/*
** play.c for cmp in /home/guillaume/Documents/Projets/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Wed Apr 20 16:25:29 2016 guillaume
** Last update Mon May  2 17:16:45 2016 Mineshot03
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
      system("clear");
      copyright_display();
      display_conf();
      printf("%s ", "►");
      printf("%d/%d - %s\n", lecture + 1, music.nbsong, music.playlist[lecture]);
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
	  system("clear");
	  copyright_display();
	  display_conf();
	  printf("%s ", "►");
	  printf("%d/%d - %s\n", lecture + 1, music.nbsong, music.playlist[lecture]);
	}
      /*else if (cmd == 's')
      pause();
      */
      cmd = 0;
    }
  return (0);
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
  system("clear");
  copyright_display();
  display_conf();
  printf("%s ", "►");
  printf("%d/%d - %s\n", lecture + 1, music.nbsong, music.playlist[lecture]);
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
  system("clear");
  copyright_display();
  display_conf();
  printf("%s ", "►");
  printf("%d/%d - %s\n", lecture + 1, music.nbsong, music.playlist[lecture]);
  return (lecture);
}
