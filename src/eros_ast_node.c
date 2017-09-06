#include "eros_ast_node.h"

#include <stdlib.h>

eros_ast_node_t* eros_ast_node_new(void)
{
  eros_ast_node_t* node = malloc(sizeof(eros_ast_node_t));

  node->children_count = 0;
  node->children = NULL;

  return node;
}

void eros_ast_node_delete(eros_ast_node_t* node)
{
  if (!node) {
    return;
  }

  children_count_t len = node->children_count;
  for (children_count_t i = 0; i < len; i++) {
    eros_ast_node_delete(node->children[i]);
    node->children[i] = NULL;
  }

  if (node->children) {
    free(node->children);
    node->children = NULL;
  }

  free(node);
}

/*
Copyright (c) 2014-2017 Lucas Gabriel Sánchez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
