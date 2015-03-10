<?hh //strict

namespace Monhacko;

<<__ConsistentConstruct>>
class JustMonad<T> {
	
	public function __construct (
		private T $value
	) {}
	
	public function value () : T {
		return $this->value;
	}
	
	public function bind<Tfn> ((function(T):Tfn) $fn) : JustMonad<Tfn> {
		return new static($fn($this->value));
	}
}