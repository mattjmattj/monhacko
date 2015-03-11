<?hh //partial

namespace Monhacko\Test;

use \PHPUnit_Framework_TestCase as TestCase;

use \Monhacko\Monad\Out;
use \Monhacko\Monad\Maybe;

class OutTest extends TestCase {
	
	public function testBind () : void {
		
		$this->expectOutputString('foo***foo');
		
		Maybe::just('foo')
			->bind($x ==> Out::write($x))
			->bind($x ==> Out::write("***$x"));
	}
	
	public function testThen () : void {
		$this->expectOutputString('foo***foo');
		
		Out::write('foo')
			->then(() ==> Out::write("***foo"));
	}
}