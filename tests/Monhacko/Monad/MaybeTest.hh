<?hh //partial

namespace Monhacko\Test;

use \PHPUnit_Framework_TestCase as TestCase;

use \Monhacko\Monad\Maybe;
use \Monhacko\Monad\Just;
use \Monhacko\Monad\Nothing;

class MaybeTest extends TestCase {
	
	public function testJust () : void {
		
		$this->assertEquals(2, Maybe::just(2)->value());
		$this->assertEquals("foobar", Maybe::just("foobar")->value());
		
		$maybe = Maybe::just(2);
		$result = $maybe->bind($x ==> Maybe::just($x * 2))
						->bind($x ==> Maybe::just($x * 3))
						->value();
				
		$this->assertEquals(12, $result);
		
		$maybe = Maybe::just("foo");
		$result = $maybe->bind( $s ==> Maybe::just(strlen($s)))
						->bind( $x ==> Maybe::just($x *2))
						->value();
						
		$this->assertEquals(6, $result);
	}
	
	public function testNothing () : void {
		
		$maybe = Maybe::nothing();
		$result = $maybe->bind($x ==> Maybe::just($x * 2))
						->bind($x ==> Maybe::just($x * 3))
						->value();
				
		$this->assertEquals(null, $result);
	}
	
	public function testMaybe () : void {
		
		$maybe = Maybe::just(2);
		$result = $maybe->bind($x ==> ($x>10) ? Maybe::just(5) : Maybe::nothing());
		
		$this->assertEquals(Maybe::nothing(), $result);
		$this->assertEquals(null, $result->value());
	}
}