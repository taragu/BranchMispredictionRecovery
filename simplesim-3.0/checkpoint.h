#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <signal.h>

struct checkpoint_t {
  int identifier;
  int counter;
  RUU_station * ruu;
  RUU_station * lsq;
  int RUU_num;
  int RUU_head;
  int RUU_tail;
  int LSQ_num;
  int LSQ_head;
  int LSQ_tail;
  int IFQ_count;
  int IFQ_fcount;
  int RUU_count;
  int RUU_fcount;
  int LSQ_count;
  int LSQ_fcount;
  RS_link * event_queue;
  RS_link * ready_queue;
  RS_link last_op;
  RS_link * rslink_free_list;
  regs_t regs;
};

#endif /* CHECKPOINT_H */
