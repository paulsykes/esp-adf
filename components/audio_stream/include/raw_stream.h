/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _RAW_STREAM_H_
#define _RAW_STREAM_H_

#include "audio_error.h"
#include "audio_element.h"
#include "audio_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Raw stream provide APIs to obtain the pipeline data without output stream or
 *        fill the pipeline data without input stream.
 *        The have two type modes, one is AUDIO_STREAM_READER,e.g.
 *        [i2s]->[filter]->[raw],[i2s]->[codec-amr]->[raw].
 *        One is AUDIO_STREAM_WRITER,e.g. [raw]->[codec-mp3]->[i2s]
 */

/**
 * Raw Stream configurations
 */
typedef struct {
    audio_stream_type_t type;   /*!< Type of stream */
} raw_stream_cfg_t;

/**
 * @brief      Initialize RAW stream
 *
 * @param      cfg   The RAW Stream configuration
 *
 * @return     The audio element handle
 */
audio_element_handle_t raw_stream_init(raw_stream_cfg_t *cfg);

/**
 * @brief      Read data from Stream
 *
 * @param      buffer       The buffer
 * @param[in]  buf_size     Maximum number of bytes to be read.
 *
 * @return     Number of bytes actually read.
 */
int raw_stream_read(char *buffer, int buf_size);

/**
 * @brief      Write data to Stream
 *
 * @param      buffer       The buffer
 * @param[in]  buf_size     Number of bytes to write
 *
 * @return     Number of bytes written
 */
int raw_stream_write(char *buffer, int buf_size);

#ifdef __cplusplus
}
#endif

#endif
