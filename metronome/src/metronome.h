#ifndef METRONOME_H
#define METRONOME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <semaphore.h>
#include <signal.h>

#define METRONOME_DEVICE_NAME "/dev/local/metronome"

typedef struct {
    int bpm;
    int time_signature_top;
    int time_signature_bottom;
    const char *pattern;
    int pause_seconds;
    pthread_t metronome_thread;
    int pause_flag;
} metronome_data_t;

typedef struct DataTableRow {
    int time_signature_top;
    int time_signature_bottom;
    int beats_in_measure;
    const char* pattern;
} DataTableRow;

DataTableRow t[] = { { 2, 4, 4, "|1&2&" }, { 3, 4, 6, "|1&2&3&" }, { 4, 4, 8,
		"|1&2&3&4&" }, { 5, 4, 10, "|1&2&3&4-5-" }, { 3, 8, 6, "|1-2-3-" }, { 6,
		8, 6, "|1&a2&a" }, { 9, 8, 9, "|1&a2&a3&a" }, { 12, 8, 12,
		"|1&a2&a3&a4&a" } };

const char* find_pattern(int time_signature_top, int time_signature_bottom);
void* metronome_thread(void *data);
int metronome_write(resmgr_context_t *ctp, io_write_t *msg, iofunc_ocb_t *ocb);
int find_num_intervals(int time_signature_top, int time_signature_bottom);


#endif // METRONOME_H
