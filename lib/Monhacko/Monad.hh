<?hh //strict

namespace Monhacko;

interface Monad<T> {
	
	public function bind<Tfn> ((function(T):Monad<Tfn>) $fn) : Monad<Tfn>;
	
	public function then<Tfn> ((function():Monad<Tfn>) $fn) : Monad<Tfn>;
	
	public function value () : ?T;
	
}