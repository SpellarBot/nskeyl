# include "nskeyld.h"


static void ev_handler(struct mg_connection *c, int ev, void *p)
{
  if (ev == MG_EV_HTTP_REQUEST) {
    struct http_message *hm = (struct http_message *) p;

    int l = strlen(fake_node_info);
    mg_send_head(c, 200, l, "Content-Type: text/plain");
    mg_printf(c, "%.*s", l, fake_node_info);
  }
}

int main(void)
{
  struct mg_mgr mgr;
  struct mg_connection *c;

  mg_mgr_init(&mgr, NULL);
  c = mg_bind(&mgr, s_http_port, ev_handler);
  mg_set_protocol_http_websocket(c);

  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}