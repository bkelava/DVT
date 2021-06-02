#ifndef __INIT_CONTROLLER_H__
#define __INIT_CONTROLLER_H__

#include <stdio.h>
#include <ctype.h>
#include "tdp_api.h"

#define INIT_FILE_NAME "config.txt"
#define INIT_KEY_SIZE 51

#define KEY_FREQ "frequency="
#define KEY_BANDWITH "bandwidth="
#define KEY_MODULE "module="
#define KEY_PROGRAM_NO "program="
#define KEY_VIDEO_PID "vpid="
#define KEY_AUDIO_PID "apid="
#define KEY_VIDEO_TYPE "vtype="
#define KEY_AUDIO_TYPE "atype="
#define KEY_CHANNEL_1 "channel_1="
#define KEY_CHANNEL_2 "channel_2="
#define KEY_CHANNEL_3 "channel_3="
#define KEY_CHANNEL_4 "channel_4="
#define KEY_CHANNEL_5 "channel_5="

/**
 * @brief Structure that defines init channel info
 */
typedef struct channel_st
{
	uint16_t videoPid;
	uint16_t audioPid;
	tStreamType videoType;
	tStreamType audioType;
} ChannelT;

/**
 * @brief Structure that defines init controller error
 */
typedef enum _InitControllerError
{
	IC_NO_ERROR = 0,
	IC_READ_ERROR,
	IC_PARSE_ERROR
} InitControllerError;

/**
 * @brief Reads init values from file
 *
 * @param  [in] file_name - path to file
 * @param  [out] freq - channel frequency
 * @param  [out] bandwidth - bandwidth
 * @param  [out] module - inital module
 * @param  [out] channel - initial channel values
 * @param  [out] program_no - initial program number
 *
 * @return init controller error code
 */
InitControllerError read_init_values(char *file_name, uint32_t *freq, uint32_t *bandwidth, t_Module *module, ChannelT *channel, uint16_t *program_no);

#endif //__INIT_CONTROLLER_H__
