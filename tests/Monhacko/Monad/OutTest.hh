<?hh //strict

namespace Monhacko\Test;

//use \PHPUnit_Framework_TestCase as TestCase;

use HackPack\HackUnit\Core\TestCase;

use \Monhacko\Monad\Out;
use \Monhacko\Monad\Maybe;

class OutTest extends TestCase {
	
	public function testBind () : void {
		
		$this->expectCallable(function() {
			Maybe::just('foo')
				->bind($x ==> Out::write($x))
				->bind($x ==> Out::write("***$x"));
		}) ->toOutputString('foo***foo');
	}
	
	public function testThen () : void {
		
		$this->expectCallable(function() {
			Out::write('foo')
				->then(() ==> Out::write("***foo"));
		}) ->toOutputString('foo***foo');
	}
}