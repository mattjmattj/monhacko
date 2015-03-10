<?hh //strict

namespace Monhacko;

<<__ConsistentConstruct>>
class VectorMonad<T> {
	
	public function __construct (
		private Vector<T> $vector
	) {}
	
	public function value () : Vector<T> {
		return $this->vector;
	}
	
	public function bind<Tfn> ((function(T):?Tfn) $fn) : VectorMonad<Tfn> {
		$result = $this->vector->map($fn)->filter($x ==> null !== $x);
		return new static($result);
	}
}