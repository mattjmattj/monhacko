<?hh //strict

namespace Monhacko;

<<__ConsistentConstruct>>
class MaybeMonad<T> {
	
	public function __construct (
		private ?T $value
	) {}
	
	public function value () : ?T {
		return $this->value;
	}
	
	public function bind<Tfn> ((function(T):Tfn) $fn) : MaybeMonad<Tfn> {
		if (null === $this->value) {
			return new static(null);
		} else {
			return new static($fn($this->value));
		}
	}
	
}