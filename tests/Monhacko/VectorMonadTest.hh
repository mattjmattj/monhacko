<?hh //partial

namespace Monhacko\Test;

use \PHPUnit_Framework_TestCase as TestCase;

use \Monhacko\VectorMonad;

class VectorMonadTest extends TestCase {
	
	public function testBasic () : void {
		
		$v = Vector {1,2,3,4,5};
		
		$this->assertEquals($v, (new VectorMonad($v))->value());
		
		$result = (new VectorMonad($v))
			->bind($x ==> $x * 2)
			->value();
				
		$expected = Vector {2,4,6,8,10};
				
		$this->assertEquals($expected, $result);
	}
	
	public function testNull () : void {
		$v = Vector {1,2,3,4,5};
		
		$result = (new VectorMonad($v))
			->bind($x ==> ($x % 2) ? null : $x / 2)
			->bind($x ==> $x * 3)
			->value();
				
		$expected = Vector {3,6};
				
		$this->assertEquals($expected, $result);
	}
}