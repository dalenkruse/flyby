#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define MAX_NUM_CHARS 1024
void show_help(const char *name, struct option long_options[], const char *short_options, char variable_names[][MAX_NUM_CHARS], char descriptions[][MAX_NUM_CHARS])
{
	printf("\nUsage:\n");
	printf("%s [options]\n\n", name);
	printf("Options:\n");
	int index = 0;
	while (true) {
		//initialize display string
		char display_string[2*MAX_NUM_CHARS] = {' '};
		for (int i=0; i < 2*MAX_NUM_CHARS-1; i++) {
			display_string[i] = ' ';
		}

		if (long_options[index].name == 0) {
			break;
		}

		//display short option
		if (short_options[index] != ':') {
			display_string[1] = '-';
			display_string[2] = short_options[index];
			display_string[3] = ',';
		}
		
		//display long option
		memcpy(display_string + 5, "--", 2);
		memcpy(display_string + 7, long_options[index].name, strlen(long_options[index].name));
		if (long_options[index].has_arg != no_argument) {
			display_string[7 + strlen(long_options[index].name)] = '=';
			memcpy(display_string + 7 + strlen(long_options[index].name) + 1, variable_names[index], strlen(variable_names[index]));
		}

		//display long option description
		int string_pos_longopt = 40;
		memcpy(display_string + string_pos_longopt, descriptions[index], strlen(descriptions[index]));
		display_string[string_pos_longopt + strlen(descriptions[index]) + 1] = '\0';
		index++;
		
		printf("%s\n", display_string);
	}
}

#define OPT_ROTCTL_UPDATE_INTERVAL 200
#define OPT_ROTCTL_PORT 201
#define OPT_UPLINK_PORT 202
#define OPT_UPLINK_VFO 203
#define OPT_DOWNLINK_PORT 204
#define OPT_DOWNLINK_VFO 205
#define OPT_LONGITUDE 206
#define OPT_LATITUDE 207

int main (int argc, char **argv)
{
	static int verbose_flag = 0;
	int c;
	static struct option long_options[] = {
		{"update-tle-db",		required_argument,	0,	'u'},
		{"tle-file",			required_argument,	0,	't'},
		{"qth-file",			required_argument,	0,	'q'},
		{"rotctl",			required_argument,	0,	'a'},
		{"rotctl-update-interval",	required_argument,	0,	OPT_ROTCTL_UPDATE_INTERVAL},
		{"rotctl-port",			required_argument,	0,	OPT_ROTCTL_PORT},
		{"horizon",			required_argument,	0,	'H'},
		{"uplink",			required_argument,	0,	'U'},
		{"uplink-port",			required_argument,	0,	OPT_UPLINK_PORT},
		{"uplink-vfo",			required_argument,	0,	OPT_UPLINK_VFO},
		{"downlink",			required_argument,	0,	'D'},
		{"downlink-port",		required_argument,	0,	OPT_DOWNLINK_PORT},
		{"downlink-vfo",		required_argument,	0,	OPT_DOWNLINK_VFO},
		{"longitude",			required_argument,	0,	OPT_LONGITUDE},
		{"latitude",			required_argument,	0,	OPT_LATITUDE},
		{"help",			no_argument,		0,	'h'},
		{0, 0, 0, 0}
	};
	char short_options[] = "utqa::HU::D::::h";
	char descriptions[][MAX_NUM_CHARS] = {
		"update TLE database",
		"use TLE file",
		"use QTH file",
		"connect to a rotctl server and enable antenna tracking",
		"send azimuth/elevation to rotctl at a specified interval instead of when they change",
		"specify port of rotctl server",
		"specify horizon above which flyby will start tracking an orbit",
		"connect to a rigctl server for uplink frequency steering",
		"specify rigctl uplink port",
		"specify rigctl uplink VFO",
		"connect to a rigctl server for downlink frequency steering",
		"specify rigctl downlink port",
		"specify rigctl downlink VFO",
		"specify longitude display convention. Defaults to EAST",
		"specify latitude display convention. Defaults to NORTH",
		"show help"};
	char variable_names[][MAX_NUM_CHARS] = {
		"FILE",
		"FILE",
		"FILE",
		"SERVER_HOST",
		"SECONDS",
		"SERVER_PORT",
		"HORIZON",
		"SERVER_HOST",
		"SERVER_PORT",
		"UPLINK_VFO_NAME",
		"SERVER_HOST",
		"SERVER_PORT",
		"DOWNLINK_VFO_NAME",
		"EAST/WEST",
		"NORTH/SOUTH",
		""};

	while (1) {
		int option_index = 0;
		c = getopt_long(argc, argv, short_options, long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {
			case 'u': //updatefile
				break;
			case 't': //tlefile
				break;
			case 'q': //qth
				break;
			case 'a': //rotctl
				break;
			case OPT_ROTCTL_UPDATE_INTERVAL: //rotctl update interval
				break;
			case OPT_ROTCTL_PORT: //rotctl port
				break;
			case 'H': //horizon
				break;
			case 'U': //uplink
				break;
			case OPT_UPLINK_PORT: //uplink port
				break;
			case OPT_UPLINK_VFO: //uplink vfo
				break;
			case 'D': //downlink
				break;
			case OPT_DOWNLINK_PORT: //downlink port
				break;
			case OPT_DOWNLINK_VFO: //downlink vfo
				break;
			case OPT_LONGITUDE: //longitude
				break;
			case OPT_LATITUDE: //latitude
				break;
			case 'h': //help
				show_help(argv[0], long_options, short_options, variable_names, descriptions);
				break;
		}
	}
}