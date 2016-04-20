/*
** play.c for cmp in /home/guillaume/Documents/Projets/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Wed Apr 20 16:25:29 2016 guillaume
** Last update Wed Apr 20 17:00:08 2016 guillaume
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
  chdir(path_music);

}

void	play()
{
  FMOD_RESULT	result;
  int	key;

  result = FMOD_Channel_IsPlaying(music.channel, &music.isplaying);
  checkerror(result);

  if (!music.isplaying)
    {
      if ((file = readdir(rep)) == NULL)
	{
	  rewinddir(rep);
	  if ((file = readdir(rep)) == NULL)
	    exit(-1);
	}
      FMOD_Sound_Release(music.music);
      result = FMOD_System_CreateSound(music.system, file->d_name, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music.music);
      if (result == FMOD_OK)
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, music, 0, &channel);
    }

}

int	main()
{
  path_music = "yolo";
  init_system();
  play();
}
