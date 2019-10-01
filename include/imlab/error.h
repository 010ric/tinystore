// ---------------------------------------------------------------------------
// IMLAB
// ---------------------------------------------------------------------------

#ifndef INCLUDE_IMLAB_ERROR_H_
#define INCLUDE_IMLAB_ERROR_H_

#include <stdexcept>

namespace imlab {

struct NotImplementedException: std::runtime_error {
    /// Constructor
    NotImplementedException()
        : std::runtime_error("not implemented") {}
};

}  // namespace imlab

#endif  // INCLUDE_IMLAB_ERROR_H_
