<?hh //strict

namespace Monhacko\Monad;

use Monhacko\Monad;
use Monhacko\Monad\Maybe;

class Out<T> implements Monad<T> {
	
	private function __construct (
		private T $value
	) {}
	
	public static function write<Tout> (Tout $value) : Out<Tout> {
		echo $value;
		return new Out($value);
	}
	
	public function bind<Tfn> ((function(T):Monad<Tfn>) $fn) : Monad<Tfn> {
		return $fn($this->value);
	}
	
	public function then<Tfn> ((function():Monad<Tfn>) $fn) : Monad<Tfn> {
		return $fn();
	}
	
	public function value () : ?T {
		return $this->value;
	}
}