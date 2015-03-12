<?hh //strict

namespace Monhacko\Test;

//use \PHPUnit_Framework_TestCase as TestCase;

use HackPack\HackUnit\Core\TestCase;

use \Monhacko\Monad\Maybe;

class MaybeTest extends TestCase {
	
	public function testJust () : void {
		
		$this->expect(Maybe::just(2)->value())->toEqual(2);
		$this->expect(Maybe::just("foobar")->value())->toEqual("foobar");
		
		$maybe = Maybe::just(2);
		$result = $maybe->bind($x ==> Maybe::just($x * 2))
						->bind($x ==> Maybe::just($x * 3))
						->value();
				
		$this->expect($result)->toEqual(12);
		
		$maybe = Maybe::just("foo");
		$result = $maybe->bind( $s ==> Maybe::just(strlen($s)))
						->bind( $x ==> Maybe::just($x *2))
						->value();
						
		$this->expect($result)->toEqual(6);
	}
	
	public function testNothing () : void {
		
		$maybe = Maybe::nothing();
		$result = $maybe->bind($x ==> Maybe::just($x * 2))
						->bind($x ==> Maybe::just($x * 3))
						->value();
				
		$this->expect($result)->toEqual(null);
	}
	
	public function testMaybe () : void {
		
		$maybe = Maybe::just(2);
		$result = $maybe->bind($x ==> ($x>10) ? Maybe::just(5) : Maybe::nothing());
		
		$this->expect($result)->toEqual(Maybe::nothing());
		$this->expect($result->value())->toEqual(null);
	}
	
	public function testThen () : void {
		
		$maybe = Maybe::nothing();
		
		$fn = function ($x, &$buffer) {
			return function() use ($x, &$buffer) {
				$buffer[] = $x;
				return Maybe::nothing();
			};
		};

		$buffer = [];
		
		$maybe->then($fn(1,$buffer))->then($fn(2,$buffer));
		
		$this->expect($buffer)->toEqual([1,2]);
	}
}