/*
 * Copyright (c) 2015, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0, as
 * published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an
 * additional permission to link the program and your derivative works
 * with the separately licensed software that they have included with
 * MySQL.
 *
 * Without limiting anything contained in the foregoing, this file,
 * which is part of MySQL Connector/C++, is also subject to the
 * Universal FOSS Exception, version 1.0, a copy of which can be found at
 * http://oss.oracle.com/licenses/universal-foss-exception.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <mysql/cdk/foundation/common.h>
//include socket_detail.h before ssl.h because it includes winsock2.h
//which must be included before winsock.h
#include "socket_detail.h"
PUSH_SYS_WARNINGS
#include <openssl/ssl.h>
#ifdef WITH_SSL_WOLFSSL

// Wolfssl redefines close, which causes compiler errors in VS.
// Therefore, we have to undef it.
#ifdef _WIN32
#undef close
#endif

#else
#include <openssl/err.h>
#endif
POP_SYS_WARNINGS
#include <mysql/cdk/foundation/error.h>
#include <mysql/cdk/foundation/connection_openssl.h>
#include <mysql/cdk/foundation/opaque_impl.i>
#include "connection_tcpip_base.h"


#ifdef WITH_SSL_WOLFSSL
static const char* tls_ciphers_list="RC4-SHA:RC4-MD5:DES-CBC3-SHA:AES128-SHA:AES256-SHA:"
                                    "NULL-SHA:NULL-SHA256:"
                                    "DHE-RSA-AES128-SHA:DHE-RSA-AES256-SHA:"
                                    "DHE-PSK-AES256-GCM-SHA384:DHE-PSK-AES128-GCM-SHA256:"
                                    "DHE-PSK-AES256-CBC-SHA384:DHE-PSK-AES128-CBC-SHA256:"
                                    "DHE-PSK-AES128-CCM:DHE-PSK-AES256-CCM:"
                                    "DHE-PSK-NULL-SHA384:DHE-PSK-NULL-SHA256:"
                                    "DHE-RSA-AES128-SHA256:DHE-RSA-AES256-SHA256:"
                                    "DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384:"
                                    "DHE-RSA-CAMELLIA128-SHA:DHE-RSA-CAMELLIA256-SHA:"
                                    "DHE-RSA-CAMELLIA128-SHA256:DHE-RSA-CAMELLIA256-SHA256:"
                                    "DHE-RSA-CHACHA20-POLY1305:DHE-RSA-CHACHA20-POLY1305-OLD:"
                                    "DHE-PSK-CHACHA20-POLY1305:"
                                    "PSK-AES256-GCM-SHA384:PSK-AES128-GCM-SHA256:"
                                    "PSK-AES256-CBC-SHA384:PSK-AES128-CBC-SHA256:"
                                    "PSK-AES128-CBC-SHA:PSK-AES256-CBC-SHA:"
                                    "PSK-AES128-CCM:PSK-AES256-CCM:"
                                    "PSK-AES128-CCM-8:PSK-AES256-CCM-8:"
                                    "PSK-NULL-SHA384:PSK-NULL-SHA256:PSK-NULL-SHA:"
                                    "PSK-CHACHA20-POLY1305:"
                                    "HC128-MD5:HC128-SHA:HC128-B2B256:"
                                    "AES128-B2B256:AES256-B2B256:AES128-SHA256:AES256-SHA256:"
                                    "AES128-CCM-8:AES256-CCM-8:AES128-GCM-SHA256:AES256-GCM-SHA384:"
                                    "ADH-AES128-SHA:"
                                    "RABBIT-SHA:"
                                    "NTRU-RC4-SHA:NTRU-DES-CBC3-SHA:"
                                    "NTRU-AES128-SHA:NTRU-AES256-SHA:"
                                    "ECDHE-ECDSA-AES128-CCM:ECDHE-ECDSA-AES128-CCM-8:ECDHE-ECDSA-AES256-CCM-8:"
                                    "ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES128-SHA:"
                                    "ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-RC4-SHA:ECDHE-RSA-DES-CBC3-SHA:"
                                    "ECDHE-ECDSA-RC4-SHA:ECDHE-ECDSA-DES-CBC3-SHA:"
                                    "ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:"
                                    "ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:"
                                    "ECDHE-ECDSA-NULL-SHA:ECDHE-PSK-NULL-SHA256:ECDHE-PSK-AES128-CBC-SHA256:"
                                    "ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:"
                                    "ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:"
                                    "ECDHE-RSA-CHACHA20-POLY1305:ECDHE-ECDSA-CHACHA20-POLY1305:"
                                    "ECDHE-RSA-CHACHA20-POLY1305-OLD:ECDHE-ECDSA-CHACHA20-POLY1305-OLD:"
                                    "ECDHE-PSK-CHACHA20-POLY1305:"
                                    "ECDH-RSA-AES128-SHA:ECDH-RSA-AES256-SHA:ECDH-ECDSA-AES128-SHA:"
                                    "ECDH-ECDSA-AES256-SHA:ECDH-RSA-RC4-SHA:ECDH-RSA-DES-CBC3-SHA:"
                                    "ECDH-ECDSA-RC4-SHA:ECDH-ECDSA-DES-CBC3-SHA:"
                                    "ECDH-RSA-AES128-GCM-SHA256:ECDH-RSA-AES256-GCM-SHA384:"
                                    "ECDH-ECDSA-AES128-GCM-SHA256:ECDH-ECDSA-AES256-GCM-SHA384:"
                                    "ECDH-RSA-AES128-SHA256:ECDH-ECDSA-AES128-SHA256:"
                                    "ECDH-RSA-AES256-SHA384:ECDH-ECDSA-AES256-SHA384:"
                                    "EDH-RSA-DES-CBC3-SHA:"
                                    "CAMELLIA128-SHA:CAMELLIA256-SHA:CAMELLIA128-SHA256:CAMELLIA256-SHA256:"
                                    "QSH:RENEGOTIATION-INFO:IDEA-CBC-SHA:"
                                    "TLS13-AES128-GCM-SHA256:TLS13-AES256-GCM-SHA384:"
                                    "TLS13-CHACHA20-POLY1305-SHA256:"
                                    "TLS13-AES128-CCM-SHA256:TLS13-AES128-CCM-8-SHA256:"
                                    "WDM-NULL-SHA256:"

;

#else
static const char tls_ciphers_list[]="ECDHE-ECDSA-AES128-GCM-SHA256:"
                                     "ECDHE-ECDSA-AES256-GCM-SHA384:"
                                     "ECDHE-RSA-AES128-GCM-SHA256:"
                                     "ECDHE-RSA-AES256-GCM-SHA384:"
                                     "ECDHE-ECDSA-AES128-SHA256:"
                                     "ECDHE-RSA-AES128-SHA256:"
                                     "ECDHE-ECDSA-AES256-SHA384:"
                                     "ECDHE-RSA-AES256-SHA384:"
                                     "DHE-RSA-AES128-GCM-SHA256:"
                                     "DHE-DSS-AES128-GCM-SHA256:"
                                     "DHE-RSA-AES128-SHA256:"
                                     "DHE-DSS-AES128-SHA256:"
                                     "DHE-DSS-AES256-GCM-SHA384:"
                                     "DHE-RSA-AES256-SHA256:"
                                     "DHE-DSS-AES256-SHA256:"
                                     "ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:"
                                     "ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:"
                                     "DHE-DSS-AES128-SHA:DHE-RSA-AES128-SHA:"
                                     "TLS_DHE_DSS_WITH_AES_256_CBC_SHA:DHE-RSA-AES256-SHA:"
                                     "AES128-GCM-SHA256:DH-DSS-AES128-GCM-SHA256:"
                                     "ECDH-ECDSA-AES128-GCM-SHA256:AES256-GCM-SHA384:"
                                     "DH-DSS-AES256-GCM-SHA384:ECDH-ECDSA-AES256-GCM-SHA384:"
                                     "AES128-SHA256:DH-DSS-AES128-SHA256:ECDH-ECDSA-AES128-SHA256:AES256-SHA256:"
                                     "DH-DSS-AES256-SHA256:ECDH-ECDSA-AES256-SHA384:AES128-SHA:"
                                     "DH-DSS-AES128-SHA:ECDH-ECDSA-AES128-SHA:AES256-SHA:"
                                     "DH-DSS-AES256-SHA:ECDH-ECDSA-AES256-SHA:DHE-RSA-AES256-GCM-SHA384:"
                                     "DH-RSA-AES128-GCM-SHA256:ECDH-RSA-AES128-GCM-SHA256:DH-RSA-AES256-GCM-SHA384:"
                                     "ECDH-RSA-AES256-GCM-SHA384:DH-RSA-AES128-SHA256:"
                                     "ECDH-RSA-AES128-SHA256:DH-RSA-AES256-SHA256:"
                                     "ECDH-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:"
                                     "ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA:"
                                     "ECDHE-ECDSA-AES256-SHA:DHE-DSS-AES128-SHA:DHE-RSA-AES128-SHA:"
                                     "TLS_DHE_DSS_WITH_AES_256_CBC_SHA:DHE-RSA-AES256-SHA:"
                                     "AES128-SHA:DH-DSS-AES128-SHA:ECDH-ECDSA-AES128-SHA:AES256-SHA:"
                                     "DH-DSS-AES256-SHA:ECDH-ECDSA-AES256-SHA:DH-RSA-AES128-SHA:"
                                     "ECDH-RSA-AES128-SHA:DH-RSA-AES256-SHA:ECDH-RSA-AES256-SHA:DES-CBC3-SHA";
#endif

static const char tls_cipher_blocked[]= "!aNULL:!eNULL:!EXPORT:!LOW:!MD5:!DES:!RC2:!RC4:!PSK:"
                                        "!DHE-DSS-DES-CBC3-SHA:!DHE-RSA-DES-CBC3-SHA:"
                                        "!ECDH-RSA-DES-CBC3-SHA:!ECDH-ECDSA-DES-CBC3-SHA:"
                                        "!ECDHE-RSA-DES-CBC3-SHA:!ECDHE-ECDSA-DES-CBC3-SHA:";

static void throw_openssl_error_msg(const char* msg)
{
  throw cdk::foundation::Error(cdk::foundation::cdkerrc::tls_error,
                             #ifdef WITH_SSL_WOLFSSL
                               std::string("WolfSSL: ")
                             #else
                               std::string("OpenSSL: ")
                             #endif
                               + msg);
}

static void throw_openssl_error()
{
  char buffer[512];

  ERR_error_string_n(ERR_get_error(), buffer, sizeof(buffer));

  throw_openssl_error_msg(buffer);
}

/*
  Function should be called after SSL_read/SSL_write returns error (<=0).
  It will get ssl error and throw it if needed.
  Will return normally if the error can be continued.
*/
static void throw_ssl_error(SSL* tls, int err)
{
  switch(SSL_get_error(tls, err))
  {
  case SSL_ERROR_WANT_READ:
  case SSL_ERROR_WANT_WRITE:
#ifndef WITH_SSL_YASSL
  case SSL_ERROR_WANT_CONNECT:
  case SSL_ERROR_WANT_ACCEPT:
  case SSL_ERROR_WANT_X509_LOOKUP:
# if OPENSSL_VERSION_NUMBER >= 0x10100000L
  case SSL_ERROR_WANT_ASYNC:
  case SSL_ERROR_WANT_ASYNC_JOB:
# endif
#endif
    //Will not throw anything, so function that calls this, will continue.
    break;
  case SSL_ERROR_ZERO_RETURN:
    throw cdk::foundation::connection::Error_eos();
  case SSL_ERROR_SYSCALL:
    cdk::foundation::throw_posix_error();
  case SSL_ERROR_SSL:
    throw_openssl_error();
  default:
    {
      char buffer[512];
      ERR_error_string_n(static_cast<unsigned long>(SSL_get_error(tls, err)), buffer, sizeof(buffer));
      throw_openssl_error_msg(buffer);
    }
  }
}


/*
  Implementation of TLS connection class.
*/


class connection_TLS_impl
  : public ::cdk::foundation::connection::Socket_base::Impl
{
public:

  /*
    Note: Once created, the TLS object takes ownership of the plain tcpip
    connection object (which is assumed to be dynamically allocated).
  */

  connection_TLS_impl(cdk::foundation::connection::Socket_base* tcpip,
                      cdk::foundation::connection::TLS::Options options)
    : m_tcpip(tcpip)
    , m_tls(NULL)
    , m_tls_ctx(NULL)
    , m_options(options)
  {}

  ~connection_TLS_impl()
  {
    if (m_tls)
    {
      SSL_shutdown(m_tls);
      SSL_free(m_tls);
    }

    if (m_tls_ctx)
      SSL_CTX_free(m_tls_ctx);

    delete m_tcpip;
  }

  void do_connect();

  void verify_server_cert();

  cdk::foundation::connection::Socket_base* m_tcpip;
  SSL* m_tls;
  SSL_CTX* m_tls_ctx;
  cdk::foundation::connection::TLS::Options m_options;
};


void connection_TLS_impl::do_connect()
{
  if (m_tcpip->is_closed())
    m_tcpip->connect();

  if (m_tls || m_tls_ctx)
  {
    // TLS handshake already established, exit.
    return;
  }

  try
  {
#ifndef WITH_SSL_WOLFSSL
    const
#endif
    SSL_METHOD* method = SSLv23_client_method();

    if (!method)
      throw_openssl_error();

    m_tls_ctx = SSL_CTX_new(method);
    if (!m_tls_ctx)
      throw_openssl_error();


    std::string cipher_list;
    cipher_list.append(tls_cipher_blocked);
    cipher_list.append(tls_ciphers_list);

    SSL_CTX_set_cipher_list(m_tls_ctx, cipher_list.c_str());

    if (m_options.ssl_mode()
        >=
        cdk::foundation::connection::TLS::Options::SSL_MODE::VERIFY_CA
        )
    {
      SSL_CTX_set_verify(m_tls_ctx, SSL_VERIFY_PEER , NULL);

      if (SSL_CTX_load_verify_locations(
            m_tls_ctx,
            m_options.get_ca().c_str(),
            m_options.get_ca_path().empty()
            ? NULL : m_options.get_ca_path().c_str()) == 0)
        throw_openssl_error();
    }
    else
    {
      SSL_CTX_set_verify(m_tls_ctx, SSL_VERIFY_NONE, 0);
    }

    m_tls = SSL_new(m_tls_ctx);
    if (!m_tls)
      throw_openssl_error();

    unsigned int fd = m_tcpip->get_fd();

    cdk::foundation::connection::detail::set_nonblocking(fd, false);

    SSL_set_fd(m_tls, static_cast<int>(fd));

    if(SSL_connect(m_tls) != 1)
      throw_openssl_error();

    if (m_options.ssl_mode()
        ==
        cdk::foundation::connection::TLS::Options::SSL_MODE::VERIFY_IDENTITY
        )
      verify_server_cert();

  }
  catch (...)
  {
    if (m_tls)
    {
      SSL_shutdown(m_tls);
      SSL_free(m_tls);
      m_tls = NULL;
    }

    if (m_tls_ctx)
    {
      SSL_CTX_free(m_tls_ctx);
      m_tls_ctx = NULL;
    }

    throw;
  }
}


/*
  Class used to safely delete allocated X509 cert.
  This way, no need to test cert on each possible return/throw.
*/
class safe_cert
{
  X509* m_cert;

public:
  safe_cert(X509 *cert = NULL)
    : m_cert(cert)
  {}

  ~safe_cert()
  {
    if (m_cert)
      X509_free(m_cert);
  }

  operator bool()
  {
    return m_cert != NULL;
  }

  safe_cert& operator = (X509 *cert)
  {
    m_cert = cert;
    return *this;
  }

  safe_cert& operator = (safe_cert& cert)
  {
    m_cert = cert.m_cert;
    cert.m_cert = NULL;
    return *this;
  }

  operator X509 *() const
  {
    return m_cert;
  }
};


void connection_TLS_impl::verify_server_cert()
{
  safe_cert server_cert;
  const unsigned char *cn= NULL;
  int cn_loc= -1;
  ASN1_STRING *cn_asn1= NULL;
  X509_NAME_ENTRY *cn_entry= NULL;
  X509_NAME *subject= NULL;


  server_cert = SSL_get_peer_certificate(m_tls);

  if (!server_cert)
  {
    throw_openssl_error_msg("Could not get server certificate");
  }

  if (X509_V_OK != SSL_get_verify_result(m_tls))
  {
    throw_openssl_error_msg("Failed to verify the server certificate");
  }
  /*
    We already know that the certificate exchanged was valid; the SSL library
    handled that. Now we need to verify that the contents of the certificate
    are what we expect.
  */

  /*
   Some notes for future development
   We should check host name in alternative name first and then if needed check in common name.
   Currently yssl doesn't support alternative name.
   openssl 1.0.2 support X509_check_host method for host name validation, we may need to start using
   X509_check_host in the future.
  */

  subject= X509_get_subject_name((X509 *) server_cert);
  // Find the CN location in the subject
  cn_loc= X509_NAME_get_index_by_NID(subject, NID_commonName, -1);
  if (cn_loc < 0)
  {
    throw_openssl_error_msg("Failed to get CN location in the certificate subject");
  }

  // Get the CN entry for given location
  cn_entry= X509_NAME_get_entry(subject, cn_loc);
  if (cn_entry == NULL)
  {
    throw_openssl_error_msg("Failed to get CN entry using CN location");
  }

  // Get CN from common name entry
  cn_asn1 = X509_NAME_ENTRY_get_data(cn_entry);
  if (cn_asn1 == NULL)
  {
    throw_openssl_error_msg("Failed to get CN from CN entry");
  }

#if OPENSSL_VERSION_NUMBER > 0x10100000L
  cn= ASN1_STRING_get0_data(cn_asn1);
#else
  cn= ASN1_STRING_data(cn_asn1);
#endif

  // There should not be any NULL embedded in the CN
  if ((size_t)ASN1_STRING_length(cn_asn1) != strlen(reinterpret_cast<const char*>(cn)))
  {
    throw_openssl_error_msg("NULL embedded in the certificate CN");
  }


  if (!m_options.verify_cn(reinterpret_cast<const char*>(cn)))
  {
    throw_openssl_error_msg("SSL certificate validation failure");
  }

}


IMPL_TYPE(cdk::foundation::connection::TLS, connection_TLS_impl);
IMPL_PLAIN(cdk::foundation::connection::TLS);


namespace cdk {
namespace foundation {
namespace connection {


TLS::TLS(Socket_base* tcpip,
         const TLS::Options &options)
  : opaque_impl<TLS>(NULL, tcpip, options)
{}


Socket_base::Impl& TLS::get_base_impl()
{
  return get_impl();
}


TLS::Read_op::Read_op(TLS &conn, const buffers &bufs, time_t deadline)
  : IO_op(conn, bufs, deadline)
  , m_tls(conn)
  , m_currentBufferIdx(0)
  , m_currentBufferOffset(0)
{
  connection_TLS_impl& impl = m_tls.get_impl();

  if (!impl.m_tcpip->get_base_impl().is_open())
    throw Error_eos();
}


bool TLS::Read_op::do_cont()
{
  return common_read();
}


void TLS::Read_op::do_wait()
{
  while (!is_completed())
    common_read();
}


bool TLS::Read_op::common_read()
{
  if (is_completed())
    return true;

  connection_TLS_impl& impl = m_tls.get_impl();

  const bytes& buffer = m_bufs.get_buffer(m_currentBufferIdx);
  byte* data =buffer.begin() + m_currentBufferOffset;
  int buffer_size = static_cast<int>(buffer.size() - m_currentBufferOffset);

  int result = SSL_read(impl.m_tls, data, buffer_size);

  if (result <= 0)
  {
    throw_ssl_error(impl.m_tls, result);
  }

  if (result > 0)
  {
    m_currentBufferOffset += result;

    if (m_currentBufferOffset == buffer.size())
    {
      ++m_currentBufferIdx;

      if (m_currentBufferIdx == m_bufs.buf_count())
      {
        set_completed(m_bufs.length());
        return true;
      }
    }
  }

  return false;
}


TLS::Read_some_op::Read_some_op(TLS &conn, const buffers &bufs, time_t deadline)
  : IO_op(conn, bufs, deadline)
  , m_tls(conn)
{
  connection_TLS_impl& impl = m_tls.get_impl();

  if (!impl.m_tcpip->get_base_impl().is_open())
    throw Error_eos();
}


bool TLS::Read_some_op::do_cont()
{
  return common_read();
}


void TLS::Read_some_op::do_wait()
{
  while (!is_completed())
    common_read();
}


bool TLS::Read_some_op::common_read()
{
  if (is_completed())
    return true;

  connection_TLS_impl& impl = m_tls.get_impl();

  const bytes& buffer = m_bufs.get_buffer(0);

  int result = SSL_read(impl.m_tls, buffer.begin(), (int)buffer.size());

  if (result <= 0)
  {
    throw_ssl_error(impl.m_tls, result);
  }

  if (result > 0)
  {
    set_completed(static_cast<size_t>(result));
    return true;
  }

  return false;
}


TLS::Write_op::Write_op(TLS &conn, const buffers &bufs, time_t deadline)
  : IO_op(conn, bufs, deadline)
  , m_tls(conn)
  , m_currentBufferIdx(0)
  , m_currentBufferOffset(0)
{
  connection_TLS_impl& impl = m_tls.get_impl();

  if (!impl.m_tcpip->get_base_impl().is_open())
    throw Error_no_connection();
}


bool TLS::Write_op::do_cont()
{
  return common_write();
}


void TLS::Write_op::do_wait()
{
  while (!is_completed())
    common_write();
}


bool TLS::Write_op::common_write()
{
  if (is_completed())
    return true;

  connection_TLS_impl& impl = m_tls.get_impl();

  const bytes& buffer = m_bufs.get_buffer(m_currentBufferIdx);
  byte* data = buffer.begin() + m_currentBufferOffset;
  int buffer_size = static_cast<int>(buffer.size() - m_currentBufferOffset);

  int result = SSL_write(impl.m_tls, data, buffer_size);

  if (result <= 0)
  {
    throw_ssl_error(impl.m_tls, result);
  }

  if (result > 0)
  {
    m_currentBufferOffset += result;

    if (m_currentBufferOffset == buffer.size())
    {
      ++m_currentBufferIdx;

      if (m_currentBufferIdx == m_bufs.buf_count())
      {
        set_completed(m_bufs.length());
        return true;
      }
    }
  }

  return false;
}


TLS::Write_some_op::Write_some_op(TLS &conn, const buffers &bufs, time_t deadline)
  : IO_op(conn, bufs, deadline)
  , m_tls(conn)
{
  connection_TLS_impl& impl = m_tls.get_impl();

  if (!impl.m_tcpip->get_base_impl().is_open())
    throw Error_no_connection();
}


bool TLS::Write_some_op::do_cont()
{
  return common_write();
}


void TLS::Write_some_op::do_wait()
{
  while (!is_completed())
    common_write();
}


bool TLS::Write_some_op::common_write()
{
  if (is_completed())
    return true;

  connection_TLS_impl& impl = m_tls.get_impl();

  const bytes& buffer = m_bufs.get_buffer(0);

  int result = SSL_write(impl.m_tls, buffer.begin(), (int)buffer.size());

  if (result <= 0)
  {
    throw_ssl_error(impl.m_tls, result);
  }

  if (result > 0)
  {
    set_completed(static_cast<size_t>(result));
    return true;
  }

  return false;
}


}  // namespace connection
}  // namespace foundation
}  // namespace cdk
