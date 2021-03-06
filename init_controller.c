/****************************************************************************
*
* Univerzitet u Novom Sadu, Fakultet tehnickih nauka
* Katedra za Računarsku Tehniku i Računarske Komunikacije
*
* -----------------------------------------------------
* Ispitni zadatak iz predmeta:
*
* PROGRAMSKA PODRSKA U TELEVIZIJI I OBRADI SLIKE
* -----------------------------------------------------
* Aplikacija za TV prijemnik
* -----------------------------------------------------
*
* \file init_controller.c
* \brief
* 	This module is used to read initial values from a file.
*
* @Author Mario Peric
*****************************************************************************/
#include "init_controller.h"

InitControllerError read_init_values(char *file_name, uint32_t *freq, uint32_t *bandwidth, t_Module *module, ChannelT *channel, uint16_t *program_no)
{
	FILE *f;

	char key[INIT_KEY_SIZE];
	char value[INIT_KEY_SIZE];

	f = fopen(file_name, "r");
	if (f == NULL)
	{
		return IC_READ_ERROR;
	}

	while (fscanf(f, "%s %s", key, value) != EOF)
	{
		printf("key %d value %d\n");
		if (!strcmp(key, KEY_FREQ))
		{
			*freq = atoi(value);
			printf("FREQ CUST %d\n", *freq);
		}
		else if (!strcmp(key, KEY_BANDWITH))
		{
			*bandwidth = atoi(value);
		}
		else if (!strcmp(key, KEY_MODULE))
		{
			if (!strcmp(value, "DVB_T"))
			{
				*module = DVB_T;
			}
			else if (!strcmp(value, "DVB_T2"))
			{
				*module = DVB_T2;
			}
			else
			{
				printf("Unknown value for key: 'module': %s\n", value);
				return IC_PARSE_ERROR;
			}
		}
		else if (!strcmp(key, KEY_PROGRAM_NO))
		{
			*program_no = atoi(value);
		}
		else if (!strcmp(key, KEY_VIDEO_PID))
		{
			channel->videoPid = atoi(value);
		}
		else if (!strcmp(key, KEY_AUDIO_PID))
		{
			channel->audioPid = atoi(value);
		}
		else if (!strcmp(key, KEY_VIDEO_TYPE))
		{
			if (!strcmp(value, "mpeg2"))
				channel->videoType = 42;
			else
				return IC_READ_ERROR;
		}
		else if (!strcmp(key, KEY_AUDIO_TYPE))
		{
			if (!strcmp(value, "ac3"))
				channel->audioType = 10;
			else
				return IC_READ_ERROR;
		}
		else if (!strcmp(key, KEY_CHANNEL_1) || !strcmp(key, KEY_CHANNEL_2) || !strcmp(key, KEY_CHANNEL_3) || !strcmp(key, KEY_CHANNEL_4) || !strcmp(key, KEY_CHANNEL_5))
		{
			printf("NO USE OF PARTENTAL RATING FOR CHANNEL \n");
		}
		else
		{
			printf("Unknown key value: %s\n", key);
			return IC_PARSE_ERROR;
		}
	}

	return IC_NO_ERROR;
}
