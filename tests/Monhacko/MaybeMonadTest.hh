<?hh //partial

namespace Monhacko\Test;

use \PHPUnit_Framework_TestCase as TestCase;

use \Monhacko\MaybeMonad;

class MaybeMonadTest extends TestCase {
	
	public function testBasic () : void {
		
		$this->assertEquals(2, (new MaybeMonad(2))->value());
		$this->assertEquals(null, (new MaybeMonad(null))->value());
		$this->assertEquals("foobar", (new MaybeMonad("foobar"))->value());
		
		$maybe = new MaybeMonad(2);
		$result = $maybe->bind($x ==> $x * 2)
						->bind($x ==> $x * 3)
						->value();
				
		$this->assertEquals(12, $result);
	}
	
	public function testBasicWhenNull () : void {
		
		$maybe = new MaybeMonad(null);
		$result = $maybe->bind($x ==> $x * 2)
						->bind($x ==> $x * 3)
						->value();
				
		$this->assertEquals(null, $result);
	}
	
	public function testChangingType () : void {
		$maybe = new MaybeMonad("foo");
		$result = $maybe->bind((string $s) : int ==> strlen($s))
						->bind((int $x) : int ==> $x *2)
						->value();
						
		$this->assertEquals(6, $result);
	}
}