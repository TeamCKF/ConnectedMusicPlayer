/*
** play.c for cmp in /home/guillaume/Documents/Projets/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Wed Apr 20 16:25:29 2016 guillaume
** Last update Fri Apr 22 02:20:54 2016 Frédéric GOMEL
*/

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fmod.h>
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
  load_playlist();
}

/*int	play()
{
  FMOD_RESULT	result;
  int	key;

  FMOD_Channel_IsPlaying(music.channel, &music.isplaying);

  if (!music.isplaying)
    {
      result = -1;
      while (result != FMOD_OK)
	{
	  if ((music.file = readdir(music.rep)) == NULL)
	    {
	      rewinddir(music.rep);
	      music.file = readdir(music.rep);
	    }
	  FMOD_Sound_Release(music.music);
	  result = FMOD_System_CreateSound(music.system, music.file->d_name, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
	}
      FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
      system("clear");
      printf("%s\n", music.file->d_name);
    }
  if (kbhit())
    {
      key = getch();

      if (key == 'q')
	quit();
      else if (key == 'n')
	next_music();
      else if (key == 'p')
	prev_music();
      else if (key == 's')
	pause();
    }
  return (0);
  }*/

void	quit()
{
  closedir(music.rep);
  FMOD_Sound_Release(music.music);
  FMOD_System_Close(music.system);
  FMOD_System_Release(music.system);
  exit(0);
}
/*
void	next_music()
{
  FMOD_RESULT	result;

  FMOD_Sound_Release(music.music);
  result = -1;
  while (result != FMOD_OK)
    {
      if ((music.file = readdir(music.rep)) == NULL)
	{
	  rewinddir(music.rep);
	  if ((music.file = readdir(music.rep)) == NULL)
	    exit(-1);
	}
      result = FMOD_System_CreateSound(music.system, music.file->d_name, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
      if (result == FMOD_OK)
	FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
    }
  system("clear");
  printf("%s\n", music.file->d_name);
  return ;
  }*/

/*void	prev_music()
{
  FMOD_RESULT	result;
  long int	cursor;

  result = -1;
  cursor = telldir(music.rep);
  FMOD_Sound_Release(music.music);
  while (result != FMOD_OK)
    {
      //cursor--;
      if (cursor < 0)
	{
	  while ((music.file = readdir(music.rep)) == NULL);
	  cursor = telldir(music.rep);
	}
      seekdir(music.rep, 6);
      music.file = readdir(music.rep);
      result = FMOD_System_CreateSound(music.system, music.file->d_name, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
      if (result == FMOD_OK)
	FMOD_System_PlaySound(music.system, FMOD_CHANNEL_FREE, music.music, 0, &music.channel);
    }
  system("clear");
  printf("%d    %s\n", cursor, music.file->d_name);
  return ;
  }*/
