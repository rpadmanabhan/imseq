// ============================================================================
// IMSEQ - An immunogenetic sequence analysis tool
// (C) Charite, Universitaetsmedizin Berlin
// Author: Leon Kuchenbecker
// ============================================================================
// 
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License version 2 as published by
// the Free Software Foundation.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
// 
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// ============================================================================

// ============================================================================
// HEADER FILE DESCRIPTION
// ============================================================================
// 
// ============================================================================

#ifndef IMSEQ_RUNTIME_OPTIONS_H
#define IMSEQ_RUNTIME_OPTIONS_H

#include <string>

#include <seqan/basic.h>
#include <seqan/sequence.h>

#include "sequence_data.h"

#define AUTO_TUNE -1u

struct CdrOptions {
    CharString refFasta ;
    CharString rlogPath;
    std::string bstPath;
    CharString aminoOut;
    CharString nucOut;
    CharString aminoOutBc;
    CharString nucOutBc;
    CharString fullOut;
    std::string outFileBaseName;
    unsigned vCrop;
    unsigned jCrop;
    int qmin;
    int bcQmin;
    unsigned maxQClusterErrors;
    unsigned maxSClusterErrors;
    double maxClusterRatio;
    int maxQualityValue;
    int jobs;
    int pairedMinVOverlap;
    unsigned trunkReads;
    unsigned maxBlockSize;
    double minSdDevi;
    double qminclust;
    bool reverse;
    bool mergeAllels;
    bool cacheMatches;
    bool qualClustering;
    bool simpleClustering;
    bool mergeIdenticalCDRs;
    bool pairedEnd;
    bool bcRevRead;
    bool outputAligments;
    double maxErrRateV;
    double maxErrRateJ;
    double pairedMaxErrRateVOverlap;
    unsigned maxVCoreErrors;
    unsigned maxJCoreErrors;
    unsigned vSCFLength;
    unsigned jSCFLength;
    int vSCFOffset;
    int jSCFOffset;
    bool vSCFLengthAuto;
    unsigned vReadCrop;
    unsigned barcodeLength;
    unsigned barcodeMaxError;
    bool barcodeVDJRead;
    double bcClustMaxErrRate;
    double bcClustMaxFreqRate;
    bool singleEndFallback;
    unsigned minReadLength;
    unsigned minCDR3Length;
    bool rdtWithSequence;
    bool sortOutputFiles;
    
    CdrOptions() : qmin(0), bcQmin(0), jobs(1), reverse(false), mergeAllels(false), cacheMatches(false), qualClustering(false), simpleClustering(false), mergeIdenticalCDRs(false), pairedEnd(false), bcRevRead(false), maxErrRateV(0), maxErrRateJ(0), maxVCoreErrors(0), maxJCoreErrors(0), vSCFLength(0), jSCFLength(0), vSCFOffset(-999), jSCFOffset(-999), vSCFLengthAuto(false), vReadCrop(0), barcodeLength(0), barcodeMaxError(0), barcodeVDJRead(false), bcClustMaxErrRate(0), bcClustMaxFreqRate(0), singleEndFallback(false), minReadLength(0), minCDR3Length(0), rdtWithSequence(false), sortOutputFiles(false) {}
};

// ============================================================================
// Getter for V/J segment alignment parameters
// ============================================================================

inline unsigned getSCFOffset(CdrOptions const & options, LeftOverlap const)
{
    return options.vSCFOffset;
}

inline unsigned getSCFOffset(CdrOptions const & options, RightOverlap const)
{
    return options.jSCFOffset;
}

inline unsigned getMaxCoreSegErrors(CdrOptions const & options, LeftOverlap const)
{
    return options.maxVCoreErrors;
}

inline unsigned getMaxCoreSegErrors(CdrOptions const & options, RightOverlap const)
{
    return options.maxJCoreErrors;
}

inline double getMaxSegErrorRate(CdrOptions const & options, LeftOverlap const)
{
    return options.maxErrRateV;
}

inline double getMaxSegErrorRate(CdrOptions const & options, RightOverlap const)
{
    return options.maxErrRateJ;
}
//
// ============================================================================
// Getter for maximum error rate
// ============================================================================

inline double getMaxErrRate(CdrOptions const & options, LeftOverlap const)
{
    return options.maxErrRateV;
}

inline double getMaxErrRate(CdrOptions const & options, RightOverlap const)
{
    return options.maxErrRateJ;
}

#endif
