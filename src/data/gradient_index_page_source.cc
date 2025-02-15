/*!
 * Copyright 2021-2022 by XGBoost Contributors
 */
#include "gradient_index_page_source.h"

namespace xgboost {
namespace data {
void GradientIndexPageSource::Fetch() {
  if (!this->ReadCache()) {
    auto const& csr = source_->Page();
    this->page_.reset(new GHistIndexMatrix());
    CHECK_NE(cuts_.Values().size(), 0);
    this->page_->Init(*csr, feature_types_, cuts_, max_bin_per_feat_, is_dense_,
                      sparse_thresh_, nthreads_);
    this->WriteCache();
  }
}
}  // namespace data
}  // namespace xgboost
