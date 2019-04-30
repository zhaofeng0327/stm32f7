#include "bll_log.h"
#include "fml_log.h"

void bll_log_init(log_upload_cb cb)
{
    fml_log_init(cb);
}
