/*
** mrb_haconiwa.c - Haconiwa class
**
** Copyright (c) Uchio Kondo 2017
**
** See Copyright Notice in LICENSE
*/

#include <mruby.h>
#include <mruby/data.h>

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_haconiwa_data;

static const struct mrb_data_type mrb_haconiwa_data_type = {
    "mrb_haconiwa_data", mrb_free,
};

static mrb_value mrb_haconiwa_init(mrb_state *mrb, mrb_value self)
{
  mrb_haconiwa_data *data;
  char *str;
  int len;

  data = (mrb_haconiwa_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_haconiwa_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_haconiwa_data *)mrb_malloc(mrb, sizeof(mrb_haconiwa_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

/* static mrb_value mrb_haconiwa_hello(mrb_state *mrb, mrb_value self) */
/* { */
/*   mrb_haconiwa_data *data = DATA_PTR(self); */

/*   return mrb_str_new(mrb, data->str, data->len); */
/* } */

/* static mrb_value mrb_haconiwa_hi(mrb_state *mrb, mrb_value self) */
/* { */
/*   return mrb_str_new_cstr(mrb, "hi!!"); */
/* } */

void mrb_haconiwa_stats_gem_init(mrb_state *mrb)
{
  struct RClass *haconiwa, *stats;
  haconiwa = mrb_define_module(mrb, "Haconiwa");
  stats = mrb_define_class_under(mrb, haconiwa, "Stats", mrb->object_class);
  mrb_define_method(mrb, stats, "initialize", mrb_haconiwa_init, MRB_ARGS_REQ(1));
  DONE;
}

void mrb_haconiwa_stats_gem_final(mrb_state *mrb)
{
}
