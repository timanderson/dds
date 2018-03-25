/*
   DDS, a bridge double dummy solver.

   Copyright (C) 2006-2014 by Bo Haglund /
   2014-2018 by Bo Haglund & Soren Hein.

   See LICENSE and README.
*/

#ifndef DDS_ABSEARCH_H
#define DDS_ABSEARCH_H


#define DDS_POS_LINES 5
#define DDS_HAND_LINES 12
#define DDS_NODE_LINES 4
#define DDS_FULL_LINE 80
#define DDS_HAND_OFFSET 16
#define DDS_HAND_OFFSET2 12
#define DDS_DIAG_WIDTH 34


bool ABsearch(
  struct pos * posPoint,
  const int target,
  const int depth,
  struct ThreadData * thrp);

bool ABsearch0(
  struct pos * posPoint,
  const int target,
  const int depth,
  struct ThreadData * thrp);

bool ABsearch1(
  struct pos * posPoint,
  const int target,
  const int depth,
  struct ThreadData * thrp);

bool ABsearch2(
  struct pos * posPoint,
  const int target,
  const int depth,
  struct ThreadData * thrp);

bool ABsearch3(
  struct pos * posPoint,
  const int target,
  const int depth,
  struct ThreadData * thrp);

void Make0(
  struct pos * posPoint,
  const int depth,
  moveType const * mply);

void Make1(
  struct pos * posPoint,
  const int depth,
  moveType const * mply);

void Make2(
  struct pos * posPoint,
  const int depth,
  moveType const * mply);

void Make3(
  struct pos * posPoint,
  unsigned short int trickCards[DDS_SUITS],
  const int depth,
  moveType const * mply,
  ThreadData * thrp);

evalType Evaluate(
  pos * posPoint,
  int trump,
  ThreadData * thrp);

void DumpTopLevel(
  struct ThreadData * thrp,
  int tricks,
  int lower,
  int upper,
  int printMode);

void RankToText(
  unsigned short int rankInSuit[DDS_HANDS][DDS_SUITS],
  char text[DDS_HAND_LINES][DDS_FULL_LINE]);

#endif
