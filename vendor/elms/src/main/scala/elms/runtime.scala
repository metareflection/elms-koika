package elms.runtime

import elms.util.Logger

var Log: Logger = Logger.default

case class LMSRuntimeException(msg: String)
    extends RuntimeException(s"[ELMS internal error] $msg")

case class LMSUnsupportedException(msg: String)
    extends RuntimeException(s"Unsupported operation: $msg")

// A mistake in the program being staged rather than a shortcoming of ELMS, so
// no prefix: the message is the whole diagnostic and says what to write instead.
case class LMSStagingException(msg: String) extends RuntimeException(msg)
