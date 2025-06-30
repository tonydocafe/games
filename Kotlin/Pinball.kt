import java.awt.*
import java.awt.event.*
import javax.swing.*

fun main() {
    val frame = JFrame("Mini Pinball")
    val game = PinballGame()
    frame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
    frame.contentPane.add(game)
    frame.pack()
    frame.setLocationRelativeTo(null)
    frame.isVisible = true
    game.requestFocusInWindow()
}

class PinballGame : JPanel() {
    private var ballX = 0
    private var ballY = 0
    private var ballSpeedX = 2
    private var ballSpeedY = 3

    private var paddleX = 0
    private val paddleWidth = 100
    private val paddleHeight = 10

    private val ballSize = 20
    private var gameOver = false
    private var initialized = false // Controle de inicialização

    init {
        preferredSize = Dimension(400, 400)
        background = Color.WHITE
        isFocusable = true

        addKeyListener(object : KeyAdapter() {
            override fun keyPressed(e: KeyEvent) {
                when (e.keyCode) {
                    KeyEvent.VK_LEFT -> paddleX = maxOf(0, paddleX - 20)
                    KeyEvent.VK_RIGHT -> paddleX = minOf(width - paddleWidth, paddleX + 20)
                }
                repaint()
            }
        })

        Timer(10) {
            if (!initialized) return@Timer // Aguarda inicialização
            
            if (!gameOver) {
                ballX += ballSpeedX
                ballY += ballSpeedY

                // Rebate nas paredes laterais
                if (ballX <= 0 || ballX + ballSize >= width) {
                    ballSpeedX = -ballSpeedX
                }

                // Rebate no teto
                if (ballY <= 0) {
                    ballSpeedY = -ballSpeedY
                }

                // Colisão com a barra
                val paddleY = height - 30
                if (ballY + ballSize >= paddleY &&
                    ballY <= paddleY + paddleHeight &&
                    ballX + ballSize >= paddleX &&
                    ballX <= paddleX + paddleWidth
                ) {
                    ballSpeedY = -ballSpeedY
                    ballY = paddleY - ballSize
                }

                // Game Over
                if (ballY > height) {
                    gameOver = true
                }

                repaint()
            }
        }.start()
    }

    // Garante que o jogo só inicia após o componente ser renderizado
    override fun paintComponent(g: Graphics) {
        super.paintComponent(g)
        
        if (!initialized) {
            ballX = width / 2 - ballSize / 2
            ballY = height / 4
            paddleX = width / 2 - paddleWidth / 2
            initialized = true
        }

        // Bola
        g.color = Color.RED
        g.fillOval(ballX, ballY, ballSize, ballSize)

        // Barra
        g.color = Color.BLUE
        g.fillRect(paddleX, height - 30, paddleWidth, paddleHeight)

        // Game Over
        if (gameOver) {
            g.color = Color.BLACK
            g.font = Font("Arial", Font.BOLD, 30)
            val msg = "Game Over"
            val msgWidth = g.fontMetrics.stringWidth(msg)
            g.drawString(msg, width / 2 - msgWidth / 2, height / 2)
        }
    }
}
