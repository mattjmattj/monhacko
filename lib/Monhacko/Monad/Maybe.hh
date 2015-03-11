<?hh //strict

namespace Monhacko\Monad;

use Monhacko\Monad;

class Maybe<T> implements Monad<T> {
	
	private function __construct (
		private ?T $value = null
	) {}
	
	public static function just (T $value) : Maybe<T> {
		return new self($value);
	}
	
	public static function nothing<Tnothing> () : Maybe<Tnothing> {
		return new self();
	}
	
	public function bind<Tfn> ((function(T):Monad<Tfn>) $fn) : Monad<Tfn> {
		if (null === $this->value) {
			return Maybe::nothing();
		} else {
			return $fn($this->value);
		}
	}
	
	public function value () : ?T {
		return $this->value;
	}
}