#ifndef _NGX_HTTP_PSGI_PERL_H_INCLUDED_
#define _NGX_HTTP_PSGI_PERL_H_INCLUDED_
#include <EXTERN.h>
#include <perl.h>
#include "ngx_http_psgi_module.h"

SV *ngx_http_psgi_create_env(ngx_http_request_t *r, SV *app);

ngx_int_t ngx_http_psgi_perl_init_worker(ngx_cycle_t *cycle);
ngx_int_t
ngx_http_psgi_init_app(ngx_http_psgi_loc_conf_t *psgilcf, ngx_log_t *log);

PerlInterpreter *ngx_http_psgi_create_interpreter(ngx_conf_t *cf);

ngx_int_t ngx_http_psgi_perl_handler(ngx_http_request_t *r, ngx_http_psgi_loc_conf_t *psgilcf, void *interpreter);

ngx_int_t ngx_sv2str(ngx_http_request_t *r, ngx_str_t *dst, u_char* src, int len);
ngx_int_t ngx_http_psgi_process_response(ngx_http_request_t *r, SV *response, PerlInterpreter *perl);
ngx_int_t ngx_http_psgi_process_headers(ngx_http_request_t *r, SV *headers, SV *status);

void ngx_http_psgi_perl_exit(ngx_cycle_t *cycle);

ngx_int_t chain_buffer(ngx_http_request_t *r, u_char *p, STRLEN len, ngx_chain_t **first, ngx_chain_t **last);

#endif
