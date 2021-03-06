//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef __TRANSACTIONMASTER__
#define __TRANSACTIONMASTER__

namespace ripple {

// Tracks all transactions in memory

class TransactionMaster : beast::LeakChecked <TransactionMaster>
{
public:
    TransactionMaster ();

    Transaction::pointer            fetch (uint256 const& , bool checkDisk);
    STTx::pointer  fetch (SHAMapItem::ref item, SHAMapTreeNode:: TNType type,
                                           bool checkDisk, std::uint32_t uCommitLedger);

    // return value: true = we had the transaction already
    bool inLedger (uint256 const& hash, std::uint32_t ledger);
    bool canonicalize (Transaction::pointer* pTransaction);
    void sweep (void);

private:
    TaggedCache <uint256, Transaction> mCache;
};

} // ripple

#endif
